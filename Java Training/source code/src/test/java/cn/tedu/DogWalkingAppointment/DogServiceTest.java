package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.service.impl.DogServiceImpl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class DogServiceTest {
    @Autowired
    private DogServiceImpl m;
    @Test
    public void test01(){
        System.out.println(m.getByDogId(4));
    }
}
