package dao;

import static utils.DBUtils.fetchDBConnection;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import pojos.Buddy;

public class BuddyDaoImpl implements IBuddyDao
{
	private Connection connect;
	private PreparedStatement pst1,pst2,pst3,pst4,pst5;
	
	public BuddyDaoImpl() throws Exception {
		connect=fetchDBConnection();
		pst1=connect.prepareStatement("insert into mybuddies values (?,?,?,?,?)");
		pst2=connect.prepareStatement("select * from mybuddies where email_id=?");
		pst3=connect.prepareStatement("delete from mybuddies where email_id=?");
		pst4=connect.prepareStatement("select * from mybuddies");
		pst5=connect.prepareStatement("select * from mybuddies where dob=?");
		
		System.out.println("emp dao created....");
	}

	@Override
	public String addNewBuddy(Buddy buddy) throws SQLException {
		pst1.setString(1, buddy.getEmailId());
		pst1.setString(2,buddy.getName());
		pst1.setString(3,buddy.getPhoneNumber());
		pst1.setDate(4,buddy.getDateOfBirth());
		pst1.setString(5,buddy.getCity());
		
		int updateCount = pst1.executeUpdate();
		if(updateCount == 1)
			return "Buddy data inserted successfully.";
		return " Buddy data insertion failed!!!!";
		
	}

	@Override
	public Buddy searchBuddyByEmailId(String emailId) throws SQLException {
		
        pst2.setString(1, emailId);
		
		try (ResultSet resultSet = pst2.executeQuery()) {
			if (resultSet.next())
				return new Buddy(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4),
						resultSet.getString(5));
			else
				return null;
		}


	}

	@Override
	public String deleteBuddyByEmailId(String emailId) throws SQLException {
		pst3.setString(1,emailId);
		
		int updateCount = pst3.executeUpdate();
		if(updateCount == 1)
			return "Unfriended successfully";	
		return "try again!! no such Buddy with this Email id!!";
	}

	@Override
	public List<Buddy> displayAllBuddies() throws SQLException {
		
       List<Buddy> buddies=new ArrayList<>();
		
		try(ResultSet resultSet=pst4.executeQuery())
		{
			while(resultSet.next()) {
				buddies.add(new Buddy(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4),
						resultSet.getString(5)));
			}	
		}
		return buddies;
	
	}

	@Override
	public List<Buddy> displayAllBuddiesByDob(Date dob) throws SQLException {
		
		pst5.setDate(1, dob);

		List<Buddy> buddies = new ArrayList<>();

		try (ResultSet resultSet = pst5.executeQuery()) {
			while(resultSet.next()) {
				buddies.add(new Buddy(resultSet.getString(1), resultSet.getString(2), resultSet.getString(3), resultSet.getDate(4),
						resultSet.getString(5)));
			}	
		}
		
		return buddies;

	}
	
	public void cleanUp() throws SQLException {
		if(pst1!=null)
			pst1.close();
		if(pst2!=null)
			pst2.close();
		if(pst3!=null)
			pst3.close();
		if(pst4!=null)
			pst4.close();
		if(pst5!=null)
			pst5.close();
		if(connect!=null)
			connect.close();
		
	}

	

}
