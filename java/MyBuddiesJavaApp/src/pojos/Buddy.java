package pojos;

import java.sql.Date;

public class Buddy {
	
//Your Buddy class should capture Email Id, Name, 
//Phone Number, Date of Birth and City. 
	private String emailId;
	private String name;
	private String phoneNumber;
	private Date dateOfBirth;
	private String city;
	
	
	public Buddy(String emailId, String name, String phoneNumber, Date dateOfBirth, String city) {
		super();
		this.emailId = emailId;
		this.name = name;
		this.phoneNumber = phoneNumber;
		this.dateOfBirth = dateOfBirth;
		this.city = city;
	}

	public String getEmailId() {
		return emailId;
	}

	public void setEmailId(String emailId) {
		this.emailId = emailId;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPhoneNumber() {
		return phoneNumber;
	}

	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}


	public Date getDateOfBirth() {
		return dateOfBirth;
	}

	public void setDateOfBirth(Date dateOfBirth) {
		this.dateOfBirth = dateOfBirth;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	

	@Override
	public String toString() {
		String info=String.format("%-18s %-10s %-10s %-12s %-15s",emailId,name,phoneNumber,dateOfBirth.toString(),city);
		return info;
	}
	


}
