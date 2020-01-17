# Canal-Resort-Reservation-App
Canal Resort has asked for a "prototype" reservation form to be created.  (It is a prototype in that it will likely be a web app, but for now they want to see it as a desktop one.)  They are going to let you figure out placement of the controls on the form, and you want to do this well so that you get the eventual "build our site" contract.


Your job: create an app meeting the specifications below.  


# Page 1: Reservation Details
Use StackedWidget to make multiple pages. Check out the video tutorial first.
In Page 1,
•	The user will enter her/his name as the reservation name.
•	There are two types of rooms in terms of Size: 2 queen bed and 1 king bed.
•	There are two types of rooms in terms of View: Standard and Atrium.
o	A user can choose one room size and one view type.
•	The price of each room type is as follows:
o	A Standard 2-queen room costs $284 per night
o	An Atrium 2-queen room costs $325 per night
o	A Standard 1-king room costs $290 per night
o	An Atrium 1-king room costs $350 per night
•	The user can reserve only one room.
•	The user should be able to choose the first day of stay.
•	The user can reserve room(s) for between 1 and 7 nights.
•	The user needs to enter the total number of adults (18+ years of age) and children respectively.
o	There must be at least 1 adult. Children are optional.
o	For 2-queen room, maximum number of guests is 4.
o	For 1-king room, maximum number of guests is 3.
o	HINT – can any of this be handled using a spinbox with minimum or maximum values?
•	The user can select optional vehicle parking (for $12.75 per night).
•	The user should be able to get an idea of cost (not including taxes and fees yet) in this page in real time as they choose/change the above options.
•	This page should show ‘next’ button to proceed to the next page, once a user enters all necessary information.


# Page 2: Cost and Payment Information 
•	This page should display the charges calculated. Use multiple labels to display these. This includes Charges for:
o	Room
o	Tax (which is 15% and applies ONLY to the room charge, not parking or Resort Fee – see below for Resort fee)
o	Parking Fee - $12.75 per night
o	Resort fee - $15 per night
o	Total due
•	This page asks the user to type in the credit card information, with either a VISA, MasterCard, Discover or American Express Card. You should give a set of radio buttons for the user to choose first. 
o	Once they select the card type, they can enter their card number.  The box for entering the number should be formatted for the type of card they are using (see table at the end of this assignment). You may use dashes or another character if you prefer for separating the numbers.  Note that the 3, 4, 5, and 6 as the first digit denotes that American Express card numbers start with 3, VISA with 4 and so on. (Beyond that we are not validating credit cards for this assignment.)
o	The user should also enter the expiration date (mm/yyyy) for the card.
•	Include a ‘pay’ button which will finalize the transaction. Once clicked, a dialog message box informing that the transaction was successfully processed, then the next page will appear.
•	Include a ‘back’ button to get back to the page 1 and change the booking information.


# Page 3: Reservation Confirmation
•	Display a confirmation message with:
o	The reservation details
	First day, how many nights, room type, parking included or not, how many adults/children
o	The payment information
	Total amount
	Paid with credit card ending with xxxx (the last 4 digits)
o	If you can thank the user it’d look more polite.
•	Include a close button that will terminate the app.



# Notes:
•	[UI Control Choice] Your choice of UI element will be graded.
o	Keep the user from making errors by selecting appropriate control types AND minimum/maximum values for this controls as helpful.
o	For example, use TextBox control for data entry if that is the only way to get the entry.
	Name, etc.
o	You may want to use RadioButton, CheckBox, or other data entry controls when appropriate.
	RadioButtons for Room Type, etc.
	Checkbox for optional vehicle parking, etc.
•	[IMAGES] You MUST include at least 4 images somewhere in the app and the images should be meaningful.
o	That is, the image should be something helpful for users during the reservation process.
•	[COLORS] You MUST apply your own color palette.
o	Contrast ratio is not mandatory, but you may want to check it with your choice of colors.
•	[TEXT] Consider all text’s readability (size, color, font choice)
•	[LAYOUT] Make sure to have a nicely aligned layout. 
•	[CODING] Be sure to give all controls, variables and constants good names.  (lineEdit1 is not good) 
o	You don't have to name labels that are never referenced in code.
o	Use named (const) constants for the prices.
o	Make sure there are no “extra” event handling procedures in your code
	(that is, event handlers with no code in them).
	If you accidentally add any, you will need to remove them.



# HAND IN is to be via Canvas. 
# Deliverables:
1)	Your Demo Video. Less than 3 minutes. Make sure to include a narration.
You can upload your video file to Youtube (unlisted privacy option) and leave its link in a submission comment as an alternative.
In your demo video, TEST YOUR SOLUTION by trying the following scenario AND by trying out invalid options (what might those be???). You may use your name or any other name.
1.	Standard 2-queen room, from 6/5/2020 for 1 night with 2 adults. No parking.  
VISA 4567-9999-6666-3333; expires 12/2021
2.	King atrium room, from 7/19/2020 for 3 nights. 2 adults and 1 child. Include parking.
Discover 6565-9898-6565-9898; expires 10/2020
3.	2-Queen atrium room, from 5/30/2020 for 1 night. Total of 2 adults and 2 children. No parking.
American Express 3456-123567-12345; expires 7/2022
2)	All .h and .cpp files 
Credit card formats
issuer	Format	length
American Express	3xxx xxxxxx xxxxx	15
Visa	4xxx xxxx xxxx xxxx	16
Mastercard	5xxx xxxx xxxx xxxx	16
Discover	6xxx xxxx xxxx xxxx	16
	  
The format above is not a valid inputMask of QLineEdit. You should make your own inputMask and try. See the tutorial and references provided.
