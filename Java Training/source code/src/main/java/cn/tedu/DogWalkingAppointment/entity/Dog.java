package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class Dog extends BaseEntity implements Serializable {
    private Integer dogId;
    private Integer userId;
    private String masterName;//狗主人姓名
    private String address;//狗当前所在地址 可以实现第一个人遛完不用归还 直接到第二个人遛
    private String dogName;
    private String dogBreed;//品种
    private Integer dogAge;
    private String dogGender;
    private String isNeutered;//是否绝育
    private String isSick;//是否生病
    private String remark;//备注（习性、喜好、疾病等）
    private String imageUrl;
}
