package tester;

import static utils.ValidationUtils.validateEmail;
import static utils.ValidationUtils.validatePhoneNumber;

import java.sql.Date;
import java.util.List;
import java.util.Scanner;

import dao.BuddyDaoImpl;
import pojos.Buddy;

public class MyBuddyTester {
	
	public static void main(String[] args) 
	{
		try(Scanner scan=new Scanner(System.in))
		{
			
			boolean exit=false;
			BuddyDaoImpl dao=new BuddyDaoImpl();
			while(!exit) {
			try
			{
		    System.out.println("---------------------------------");
			System.out.println("1.Add new buddy");
			System.out.println("2.Search Buddy by Email id");
			System.out.println("3.Delete Buddy by Email id");
			System.out.println("4.Display all my buddies");
			System.out.println("5.Display all buddies by date");
			System.out.println("6.Exit");
			System.out.println("---------------------------------");
			
			switch (scan.nextInt()) 
			{
			case 1:
				System.out.println("Enter details email Id,name,phone number,date of birth(yyyy-mm-dd) and city ");
				System.out.println(dao.addNewBuddy(new Buddy(validateEmail(scan.next()),scan.next(), 
						validatePhoneNumber(scan.next()),Date.valueOf(scan.next()), scan.next())));
				
				break;
				
			case 2:	
				System.out.println("Enter Email id");
				Buddy myBuddy=dao.searchBuddyByEmailId(scan.next());
				if(myBuddy==null)
				{
					System.out.println("Record Not found!!");
				}
				else
				{
				     System.out.println(myBuddy);
				}
				
				break;
				
			case 3:
					System.out.println("Enter Email id to Unfriend");
					System.out.println(dao.deleteBuddyByEmailId(scan.next()));
				
				break;
				
			case 4:
				
				List<Buddy> myBuddies=dao.displayAllBuddies();
				if(myBuddies.isEmpty())
				{
					System.out.println("Record Not found!!");
				}else{
					System.out.println("These are your friends:");
					System.out.println(String.format("%-15s %-10s %-10s %-12s %-15s" , "Email","Name","PhoneNo","DOB","City"));
					myBuddies.forEach(buddy->System.out.println(buddy));
				}			
				break;
				
			case 5:
				System.out.println("Enter Date of birth");
				List<Buddy> myBuddiesList=dao.displayAllBuddiesByDob(Date.valueOf(scan.next()));
				
				if(myBuddiesList.isEmpty())
				{
					System.out.println("Record Not found!!");
				}else {
					
					myBuddiesList.forEach(buddy->System.out.println(buddy));
				}
						
				break;
				
			case 6: 
				dao.cleanUp();
				exit=true;
				System.out.println("Thank you!!");							
				 break;
			default:
				System.out.println("Please enter valid choice!!");
				break;
			}
					
			}
			catch (Exception e)
			{
				System.out.println(e.getStackTrace());
			}
			
		}
		}
		catch (Exception e) {
			System.out.println(e.getStackTrace());
				
         }
   }
}

