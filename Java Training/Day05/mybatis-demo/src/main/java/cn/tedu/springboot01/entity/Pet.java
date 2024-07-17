package cn.tedu.springboot01.entity;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

@Data
@NoArgsConstructor
@AllArgsConstructor

public class Pet {
    private Integer id;
    private String name;
    private String gender;
    private Date birth;
    private Date createTime;
    private Date updateTime;

}
