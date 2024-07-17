package cn.tedu.DogWalkingAppointment;

import cn.tedu.DogWalkingAppointment.entity.Appointment;
import cn.tedu.DogWalkingAppointment.mapper.AppointmentMapper;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
public class AppointmentMapperTest {
    @Autowired
    AppointmentMapper m;

    @Test
    void test1(){
        System.out.println(m.findByCustomerId(3));



    }

}
