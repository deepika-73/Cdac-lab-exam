package dao;

import java.sql.Date;
import java.sql.SQLException;
import java.util.List;

import pojos.Buddy;

public interface IBuddyDao {
	
	String addNewBuddy(Buddy buddy) throws SQLException;
	Buddy searchBuddyByEmailId(String emailId) throws SQLException;
	String deleteBuddyByEmailId(String emailId) throws SQLException;
	List<Buddy> displayAllBuddies() throws SQLException;
	List<Buddy> displayAllBuddiesByDob(Date dob) throws SQLException;


}
