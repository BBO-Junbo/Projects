package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class Appoint2 extends BaseEntity implements Serializable {
    private String customerName;//顾客姓名
    private String dogName;
    private String dogBreed;//品种
    private Integer dogAge;
    private String dogGender;
    private Date startTime;
    private Date endTime;
    private String imageUrl;
    private Integer appointmentId;
}
