package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class CustomerReview extends BaseEntity implements Serializable {
    private Integer creviewId;
    private Integer customerId;
    private Integer userId;
    private Integer appointmentId;
    private Double rating;
    private String comment;
}
