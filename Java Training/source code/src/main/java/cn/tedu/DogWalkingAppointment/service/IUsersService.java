package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.User;

public interface IUsersService {
    void reg(User user);

    User login(String username, String password, String role);
    void changePassword(Integer userId, String username, String oldPassword, String newPassword);
    User getByUid(Integer userId);
    User getByName(String name);
    void changeInfo(Integer uid, String username, User user);



}
