package cn.tedu.DogWalkingAppointment.mapper;

import cn.tedu.DogWalkingAppointment.entity.Appointment;
import cn.tedu.DogWalkingAppointment.entity.DogAvailability;

import java.util.List;

public interface AppointmentMapper {
    Integer insert(Appointment appointment);
    Appointment findByUidAndAid(Integer uid, Integer aid);
    Appointment findByAid(Integer aid);
    List<Appointment> findByCustomerId(Integer cid);
    List<Appointment> findByDogId(Integer did);
}
