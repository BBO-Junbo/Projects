package cn.tedu.DogWalkingAppointment;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("cn.tedu.DogWalkingAppointment.mapper")

public class DogWalkingAppointmentApplication {

	public static void main(String[] args) {
		SpringApplication.run(DogWalkingAppointmentApplication.class, args);
	}

}
