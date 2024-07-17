package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@AllArgsConstructor
@Data
@NoArgsConstructor
public class Customer extends BaseEntity implements Serializable {
    private Integer customerId;
    private Integer userId;
    private String customerName;
    private String address;//顾客地址（遛狗地址）
}
