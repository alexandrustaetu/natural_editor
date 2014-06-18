/* domparser.h
 * libxml++ and this file are copyright (C) 2000 by Ari Johnson, and
 * are covered by the GNU Lesser General Public License, which should be
 * included with libxml++ as the file COPYING.
 */

#ifndef __LIBXMLPP_PARSERS_DOMPARSER_H
#define __LIBXMLPP_PARSERS_DOMPARSER_H

#include <libxml++/parsers/parser.h>
#include <libxml++/dtd.h>
#include <libxml++/document.h>

namespace xmlpp {

/** DOM XML parser.
 *
 */
class DomParser : public Parser
{
public:
  /** Create a parser with an empty document.
   * @throws xmlpp::internal_error If an empty document can't be created.
   */
  DomParser();

  /** Instantiate the parser and parse a document immediately.
   * @param filename The path to the file.
   * @param validate Whether the parser should validate the XML.             
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  explicit DomParser(const Glib::ustring& filename, bool validate = false);
  virtual ~DomParser();

  /** Parse an XML document from a file.
   * If the parser already contains a document, that document and all its nodes
   * are deleted.
   * @param filename The path to the file.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  virtual void parse_file(const Glib::ustring& filename);

  /** Parse an XML document from a string.
   * If the parser already contains a document, that document and all its nodes
   * are deleted.
   * @param contents The XML document as a string.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  virtual void parse_memory(const Glib::ustring& contents);
  
  /** Parse an XML document from raw memory.
   * If the parser already contains a document, that document and all its nodes
   * are deleted.
   * @param contents The XML document as an array of bytes.
   * @param bytes_count The number of bytes in the @a contents array.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  void parse_memory_raw(const unsigned char* contents, size_type bytes_count);

  /** Parse an XML document from a stream.
   * If the parser already contains a document, that document and all its nodes
   * are deleted.
   * @param in The stream.
   * @throws xmlpp::internal_error
   * @throws xmlpp::parse_error
   * @throws xmlpp::validity_error
   */
  virtual void parse_stream(std::istream& in);

  /** Test whether a document has been parsed.
   */
  operator bool() const;
  
  /** Get the parsed document.
   * @returns A pointer to the parsed document, or <tt>0</tt>.
   */
  Document* get_document();

  /** Get the parsed document.
   * @returns A pointer to the parsed document, or <tt>0</tt>.
   */
  const Document* get_document() const;
  
protected:
  virtual void parse_context();

  virtual void release_underlying();
  
  Document* doc_;
};

} // namespace xmlpp

#endif //__LIBXMLPP_PARSERS_DOMPARSER_H
