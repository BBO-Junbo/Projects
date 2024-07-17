package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class DogAvailability extends BaseEntity implements Serializable {
    private Integer availabilityId;
    private Integer dogId;//关联狗：dog_id
    private Boolean isReserved;
    private Date startTime;//开始时间
    private Date endTime;//结束时间
}
