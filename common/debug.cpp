#include <common/debug.hpp>
//#include <boost/algorithm/string/replace.hpp>
//void escape(std::string *data) {
//    using boost::algorithm::replace_all;
//    replace_all(*data, "&", "&amp;");
//    replace_all(*data, "\"", "&quot;");
//    replace_all(*data, "\'", "&apos;");
//    replace_all(*data, "<", "&lt;");
//    replace_all(*data, ">", "&gt;");
//}

NEGLDebugDrawer::NEGLDebugDrawer() {
    1;
};

NEGLDebugDrawer::~NEGLDebugDrawer() {

};

void NEGLDebugDrawer::drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor, const btVector3& toColor) {

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.04f, 0.0f);
    glVertex3d(from.getX(), from.getY(), from.getZ());
    glColor3f(1.0f, 0.04f, 0.0f);
    glVertex3d(to.getX(), to.getY(), to.getZ());
    glEnd();
}

void NEGLDebugDrawer::drawTriangle(const btVector3& a, const btVector3& b, const btVector3& c, const btVector3& color, btScalar alpha) {
}

void NEGLDebugDrawer::drawSphere(const btVector3& p, btScalar radius, const btVector3& color) {
}

void NEGLDebugDrawer::reportErrorWarning(const char* warningString) {
}

void NEGLDebugDrawer::draw3dText(const btVector3& location, const char* textString) {
}

void NEGLDebugDrawer::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color) {
}

void NEGLDebugDrawer::drawLine(const btVector3& from, const btVector3& to, const btVector3& fromColor) {

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.04f, 0.0f);
    glVertex3d(from.getX(), from.getY(), from.getZ());
    glColor3f(1.0f, 0.04f, 0.0f);
    glVertex3d(to.getX(), to.getY(), to.getZ());
    glEnd();
}

void NEGLDebugDrawer::setDebugMode(int debug_mode) {
    this->m_debugMode = debug_mode;
}

void NEGLDebugDrawer::SetMatrices(glm::mat4 pViewMatrix, glm::mat4 pProjectionMatrix) {
    glUseProgram(0); // Use Fixed-function pipeline (no shaders)
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(&pViewMatrix[0][0]);
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(&pProjectionMatrix[0][0]);
}

/*
 high precision timing
             //auto start = std::chrono::high_resolution_clock::now();
            //auto finish = std::chrono::high_resolution_clock::now();
            //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";

 */

/*      open file, output structure

 * boost::unordered_map<std::string, string_permutation> string_permutations;
        std::vector<std::string> id_string_matches;
 * 
 * 
 * 
 *   else {

                //cout << project_obj.current_iteration->path().string();
                string line;
                ifstream myfile(project_obj.current_iteration->path().string());
                if (myfile.is_open() && test_strs++ == 10) {
                    lines_t file_lines;
                    ofstream strings_graph;
                    strings_graph.open("strings.html");
                    while (getline(myfile, line)) {
                        strings_graph << "<div class=line>\n";

                        std::istringstream teststring(line);
                        std::string st;
                        std::string lin = line;
                        escape(&lin);
                        strings_graph << "<div class=line-name>" << lin << "</div>\n";
                        line_t line_blocks;
                        while (getline(teststring, st, ' ')) {
                            strings_graph << "<div class=line-block>\n";

                            std::string tst = st.c_str();
                            std::string blo_str = tst;
                            escape(&blo_str);
                            strings_graph << "<div class=block-name>" << blo_str << "</div>\n";
                            strings_graph << "<div class=permutations>\n";
                            string_permutation str_perm;
                            str_perm.id = id_string_matches.size();
                            str_perm.occurances = 1;
                            std::pair<std::string, string_permutation> s_p = {st.c_str(), str_perm};
                            if (string_permutations.insert(s_p).second) {
                                id_string_matches.push_back(st);

                                std::string temp_str = tst.substr(0, 1);
                                int cur_length = 1;
                                int tst_len = tst.length();
                                string_ids substring_ids;
                                while (tst_len > temp_str.length()) {
                                    int cur_pos = 0;
                                    while (cur_pos <= tst_len - cur_length) {
                                        temp_str = tst.substr(cur_pos++, cur_length);

                                        s_p.first = temp_str;
                                        s_p.second.id = id_string_matches.size() + 1;
                                        //cout << id_string_matches.size();

                                        std::string perm_str = temp_str;
                                        escape(&perm_str);
                                        strings_graph << "<div class=permutation>" << perm_str << "</div>\n";


                                        if (string_permutations.insert(s_p).second) {
                                            id_string_matches.push_back(temp_str);
                                        } else {
                                            string_permutations[temp_str].occurances++;
                                        }

                                        strings_graph << "<div class=permutation-length>" << cur_length << "</div>\n";
                                        strings_graph << "<div class=permutation-id>" << string_permutations[temp_str].id << "</div>\n";
                                        strings_graph << "<div class=permutation-occurances>" << string_permutations[temp_str].occurances << "</div>\n";

                                        substring_ids.push_back(string_permutations[temp_str].id);

                                    }
                                    cur_length++;
                                }
                                string_permutations[st].children = substring_ids;
                            } else {
                                string_permutations[st].occurances++;
                            }

                            strings_graph << "<div class=block-id>" << string_permutations[tst].id << "</div>\n";
                            strings_graph << "<div class=block-occurances>" << string_permutations[tst].occurances << "</div>\n";

                            strings_graph << "</div>\n";

                            line_blocks.push_back(string_permutations[st].id);
                            strings_graph << "</div>\n";
                        }
                        strings_graph << "</div>\n";
                        file_lines.push_back(line_blocks);
                    }
                    myfile.close();
                    project_obj.project_files[file_crawl].lines = file_lines;
                }
            }
 
 
 */
