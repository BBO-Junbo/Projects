package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.User;
import cn.tedu.DogWalkingAppointment.mapper.UserMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class UserMapperTests {
    @Autowired
    private UserMapper userMapper;

    @Test
    public void Test01(){
        User user=userMapper.findByUsername("456");
        System.out.println(user);
    }
}
