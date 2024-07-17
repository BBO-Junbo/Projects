package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.User;
import org.apache.ibatis.annotations.Param;

import java.util.Date;

public interface UserMapper {
    Integer insert(User user);

    User findByUsername(String username);

    Integer updatePasswordByUid(
            @Param("userId") Integer userId,
            @Param("password") String password,
            @Param("modifiedUser") String modifiedUser,
            @Param("modifiedTime") Date modifiedTime);

    User findByUid(Integer uid);

    Integer updateInfoByUid(User user);
    Integer updateAvatar(Integer uid,String avatar,String modifiedUser, Date modifiedTime);
}
