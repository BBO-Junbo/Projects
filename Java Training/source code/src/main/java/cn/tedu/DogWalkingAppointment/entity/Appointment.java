package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class Appointment extends BaseEntity implements Serializable {
    private Integer appointmentId;//预约id
    private Integer dogId;//狗id
    private Integer customerId;//顾客id
    private Date startTime;
    private Date endTime;
}
