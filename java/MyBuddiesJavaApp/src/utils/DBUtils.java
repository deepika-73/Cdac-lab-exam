package utils;

import java.io.FileReader;
import java.sql.Connection;
import java.sql.DriverManager;
import java.util.Properties;

public class DBUtils 
{
	public static Connection fetchDBConnection() throws Exception {
		
		Properties p = new Properties();
		try (FileReader fin = new FileReader("db.properties")) {
			p.load(fin);
		}
		
		Class.forName(p.getProperty("jdbc.driver"));
		
		return DriverManager.getConnection(p.getProperty("jdbc.url"), p.getProperty("jdbc.userName"),
				p.getProperty("jdbc.password"));
	}



}
