package cn.tedu.DogWalkingAppointment.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class User extends BaseEntity implements Serializable {
    private Integer userId;
    private String username;
    private String password;
    private String salt;//给密码加盐
    private String phone;
    private String email;
    private String gender;
    private String role;
    private String avatar;//上传头像用
    private Integer isDelete;//是否删除 0表未删除
}
