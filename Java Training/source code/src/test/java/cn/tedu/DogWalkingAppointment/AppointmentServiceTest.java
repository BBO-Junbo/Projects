package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.service.impl.AppointmentServiceImpl;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class AppointmentServiceTest {
    @Autowired
    AppointmentServiceImpl s;

    @Test
    void test1(){
        System.out.println(s.findAppointmentList(2));
    }
}
