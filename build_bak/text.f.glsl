
in vec2 texpos;
uniform sampler2D tex;
uniform vec4 color;
void main(void) {
    
  //colo = vec4(1, 1, 1, texture2D(tex, texpos).a) * color;
  gl_FragColor = vec4(1, 1, 1,texture(tex, texpos).a ) * color;
  //gl_FragColor = vec4 (0.0, 0.0, 0.0, 1.0);
}
