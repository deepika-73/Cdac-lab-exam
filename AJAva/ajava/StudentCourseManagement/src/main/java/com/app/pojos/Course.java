package com.app.pojos;

import java.util.ArrayList;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.OneToMany;
import javax.persistence.Table;

@Entity
@Table(name="course")
public class Course extends BaseEntity {
	
	@Column(name="course_name",length = 20,nullable = false)
	private String courseName;
	
	@OneToMany(mappedBy = "course",cascade = CascadeType.ALL)
	private List<Student> students=new ArrayList<>();
	
	public Course() {
		System.out.println("In default Constructor"+getClass().getName());
	}

	public Course(String courseName) {
		super();
		this.courseName = courseName;
	}

	public String getCourseName() {
		return courseName;
	}

	public void setCourseName(String courseName) {
		this.courseName = courseName;
	}

	public List<Student> getStudents() {
		return students;
	}

	public void setStudents(List<Student> students) {
		this.students = students;
	}

	@Override
	public String toString() {
		return "Course [Id="+getId()+"courseName=" + courseName + "]";
	}
	
	
}
