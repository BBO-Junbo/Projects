package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.User;
import cn.tedu.DogWalkingAppointment.ex.ServiceException;
import cn.tedu.DogWalkingAppointment.service.IUsersService;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class UserServiceTests {
    @Autowired
    private IUsersService iUsersService;

    @Test
    public void login() {
        try {
            String username = "456";
            String password = "456";
            String role = "C";
            User user = iUsersService.login(username, password,role);
            System.out.println("登录成功！" + user);
        } catch (ServiceException e) {
            System.out.println("登录失败！" + e.getClass().getSimpleName());
            System.out.println(e.getMessage());
        }

    }
}