package com.app.service;

import javax.transaction.Transactional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.app.pojos.Student;
import com.app.repository.StudentRepository;

@Service
@Transactional
public class StudentServiceImpl implements IStudentService {

	
	@Autowired
	private StudentRepository repo;

	@Override
	public Student addStudent(Student student) {
		
		return repo.save(student);
	}

}
