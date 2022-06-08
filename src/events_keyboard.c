#include "../include/scop.h"

void processInput(t_scopenv *env)
{
    float cam_speed = (float)(2.5 * env->delta_time);

    if (glfwGetKey(env->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(env->window, GL_TRUE);
    if (glfwGetKey(env->window, GLFW_KEY_W) == GLFW_PRESS)
        env->cam_pos = v_v_add(env->cam_pos, v_scal_mult(env->cam_dir, cam_speed));
    if (glfwGetKey(env->window, GLFW_KEY_S) == GLFW_PRESS)
        env->cam_pos = v_v_subs(env->cam_pos, v_scal_mult(env->cam_dir, cam_speed));
    if (glfwGetKey(env->window, GLFW_KEY_A) == GLFW_PRESS)
        env->cam_pos = v_v_add(env->cam_pos, v_scal_mult(normalize(v_v_cross(env->cam_dir, env->cam_up)), cam_speed));
    if (glfwGetKey(env->window, GLFW_KEY_D) == GLFW_PRESS)
        env->cam_pos = v_v_subs(env->cam_pos, v_scal_mult(normalize(v_v_cross(env->cam_dir, env->cam_up)), cam_speed));
}