package cn.tedu.DogWalkingAppointment.service;

import cn.tedu.DogWalkingAppointment.entity.Appointment;

import java.util.Date;
import java.util.List;

public interface IAppointmentService {
    void addAppointment(Integer dogId, Integer userId, Date sTime,Date eTime);
    List<Appointment> findAppointmentList(Integer cid);
    Appointment findAppointmentByAid(Integer aid);
    List<Appointment> findAppointmentListByDogId(Integer did);
}
