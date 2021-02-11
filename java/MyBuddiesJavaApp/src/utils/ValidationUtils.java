package utils;
import java.sql.Date;

import custom_exception.InvalidInputException;
public class ValidationUtils
{
	public static Date date;
	static {
		date = Date.valueOf("1965-01-01");
	}

	
	public static String validateEmail(String Email) throws InvalidInputException
	{
		if (Email.contains("@") && Email.endsWith(".com"))
			return Email;
		else
			throw new InvalidInputException("Invalid Email ID!!!!");
	}
	
	public static String validatePhoneNumber(String phoneNo) throws InvalidInputException 
	{
		if (phoneNo.length() == 10) {
			return phoneNo;
		}
		throw new InvalidInputException("Invalid phone no.");
	}
	
	public static Date validateDateOfBirth(String dateOfBirth) throws InvalidInputException{
		Date dob = Date.valueOf(dateOfBirth);
		if (dob.after(date))
			return dob;
		throw new InvalidInputException("Date of birth must be after  1st Jan 1965. ");
	}

	

}
