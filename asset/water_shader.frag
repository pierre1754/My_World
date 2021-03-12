#version 120
uniform sampler2D currentTexture;
uniform float time;

void main(void)
{
    vec2 coord = gl_TexCoord[0].xy;
    coord.x += sin(radians(500 * time + coord.y * 500)) * 8;
    coord.y += cos(radians(500 * time + coord.x * 250)) * 12;
    vec4 pixel_color = texture2D(currentTexture, coord);
    float alpha = 0.75;

    gl_FragColor = vec4(pixel_color.xyz, min(alpha, pixel_color.w));
}
