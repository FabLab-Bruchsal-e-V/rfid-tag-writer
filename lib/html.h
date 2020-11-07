#ifndef html_h
#define html_h

String main_page=
"<html>\r\n"
"    <head>\r\n"
"      <style>\r\n"
"        body { background-color: #202020; }\r\n"
"        h2, td, a { color: #95A5A6; }\r\n"
"        p { color: white; }\r\n"
"      </style>\r\n"
"      <title>FabLab Bruchsal RFID Device Programmer</title>\r\n"
"      <meta charset=\"utf-8\">\r\n"
"    </head>\r\n"
"    <body>\r\n"
"        <h2>FabLab Bruchsal RFID Device Programmer</h2>\r\n"
"	<p>Current RFID Chip Data:</P>\r\n"
"	<form>\r\n"
"		<table>\r\n"
"			<tr>\r\n"
"				<td>Mitgliedernummer:</td>\r\n"
"				<td><input type=\"text\" name=\"memberno\" id=\"memberno\"></input></td>\r\n"
"			</tr><tr>\r\n"
"				<td>Vorname:</td>\r\n"
"				<td><input type=\"text\" name=\"firstname\" id=\"firstname\"></input></td>\r\n"
"			</tr><tr>\r\n"
"				<td>Nachname:</td>\r\n"
"				<td><input type=\"text\" name=\"lastname\" id=\"lastname\"></input></td>\r\n"
"			</tr><tr>\r\n"
"				<td><input type=\"submit\" value=\"Store to Tag\"></input></td>\r\n"
"				<td></td>\r\n"
"			</tr>\r\n"
"		</table>\r\n"
"	</form>\r\n"
"    </body>\r\n"
"</html>\r\n";
#endif
