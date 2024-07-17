package cn.tedu.DogWalkingAppointment.config;

import cn.tedu.DogWalkingAppointment.interceptor.LoginInterceptor;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import java.util.ArrayList;
import java.util.List;
@Configuration
public class LoginInterceptorConfigurer implements WebMvcConfigurer {
    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        // 创建拦截器对象
        LoginInterceptor loginInterceptor = new LoginInterceptor();

        // 白名单
        List<String> patterns = new ArrayList<>();
        patterns.add("/bootstrap3/**");
        patterns.add("/css/**");
        patterns.add("/images/**");
        patterns.add("/js/**");
        patterns.add("/web/register.html");

        patterns.add("/users/reg");
        patterns.add("/users/login");
        patterns.add("/index.html");
        patterns.add("/web/masterweb/masterlogin.html");
        patterns.add("/web/guestweb/guestlogin.html");



        // 通过注册工具添加拦截器
        registry.addInterceptor(loginInterceptor).addPathPatterns("/**").excludePathPatterns(patterns);
    }
    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry) {
        registry.addResourceHandler("/dogimg/**").addResourceLocations("file:D:/dogimg/");
    }
}
