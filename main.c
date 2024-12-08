#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Declaring variables*/
int runProgram = 1;
char exitProgram = 'n';
int telephoneContact;
int travelPartySize = 0;
char bookTour[6];
char customerId[10];
char firstName[20];
char lastName[20];
char destinationCode;
char confirmBooking;
char destination[50];
char welcomeMessage[300];
float deposit = -1;
int transportDiscount = 0;
float transportCostPerPerson = 0,
    transportCostPerPersonDiscount = 0,
    discountedTransportCostPerPerson = 0,
    transportCostTotal = 0,
    totalDiscount = 0,
    entryFeePerPerson = 0,
    entryFeeTotal = 0,
    tourGuideFee = 0,
    tripTotal =0,
    balanceDue;
int totalTours = 0, adveturamaTours = 0, momsRiversTours = 0, jollywoodParkTours = 0, confirmedBookingsTotal = 0, travellersTotal = 0, averageTravellersPerTour = 0;

int main()
{
    /*set welcome screen message*/
    strcpy(welcomeMessage, "-----------------------------------------------------------------------");
    strcat(welcomeMessage, "\nWelcome to AdventTour Tripbooker.");
    strcat(welcomeMessage, "\n----------------------------------------------------------------------");
    strcat(welcomeMessage, "\nThis software allows you to book tours for");
    strcat(welcomeMessage, "\nany of our three destinations.");
    strcat(welcomeMessage, "\n----------------------------------------------------------------------");



    /*Loop to keep programme running until the user enters exit code */
    while(runProgram == 1)
    {
        printf(welcomeMessage);
        printf("\nPress 1 to continue or 2 to exit\n");

        fflush(stdin);
        scanf("%d", &runProgram);
        if(runProgram != 1)
        {
            printf("\nAre you sure you want to exit?");
            printf("\n\tPress y to exit or any key to cancel.");
            fflush(stdin);
            scanf("%c", &exitProgram);
            if(exitProgram != 'y')
            {
                    runProgram = 1;
                continue;
            }else
            {
                break;
            }
        }
        /*initialize person details*/

        strcpy(bookTour, "y");

        /*Loop to keep booking tours until enters stop code */
        while(strcmp(bookTour, "xxx")!= 0 && strcmp(bookTour, "XXX") != 0)
        {
            printf("Enter customer ID to book a tour or 'xxx' to cancel: ");
            fflush(stdin);
            scanf("%s", bookTour);
            if(strcmp(bookTour, "xxx") == 0 || strcmp(bookTour, "XXX") == 0 )
            {
                break;
            }else
            {
                strcpy(customerId, bookTour);
            }
            printf("\n\n\nEnter tour details\n");
            printf("__________________________________________\n");


            printf("\nEnter first name: ");
            fflush(stdin);
            scanf("%s", firstName);


            printf("\nEnter last name:");
            fflush(stdin);
            scanf("%s", lastName);

            printf("\nEnter telephoneContact: ");
            fflush(stdin);
            scanf("%d", &telephoneContact);

            destinationCode = 'Z';
            while(destinationCode != 'J' && destinationCode != 'M' && destinationCode != 'A')
            {
                printf("\nEnter destination code\n\t(press J for Jollywood park), \n\t(press M for Mom's River), \n\t(press A for Adventurama): ");
                fflush(stdin);
                scanf("%c", &destinationCode);
                if(destinationCode != 'J' && destinationCode != 'M' && destinationCode != 'A')
                {
                    printf("The value you entered is invalid");
                }else
                {
                    break;
                }
            }
            travelPartySize = 0;
            while(travelPartySize < 5 || travelPartySize > 25)
            {
                printf("\nEnter the number of persons in the party\n\t(party must contain between 5 and 25 persons):");
                scanf("%d", &travelPartySize);
                fflush(stdin);
                if(travelPartySize < 5 || travelPartySize > 25)
                {
                    printf("The value you entered is invalid");
                }else
                {
                    break;
                }
            }
            deposit = -1;
            while(deposit < 0)
            {
                printf("\nHow much would you like to make deposit on this tour:");
                fflush(stdin);
                scanf("%f", &deposit);
                if(deposit < 0)
                {
                    printf("The value you entered is invalid");
                }else{
                    break;
                }
            }

            /* assign discount amount based on party size
             * 5 per cent for 10 -15 persons
             * 10 per cent for 16 to 25 persons
            */
            if(travelPartySize >= 10 && travelPartySize <=15)
            {
                transportDiscount = 5;
            }else if(travelPartySize >= 16 && travelPartySize <=25){
                transportDiscount = 10;
            }else{
                transportDiscount = 0;
            }

            /* calculate trip costs based on destination code
             *
             *
            */
            if(destinationCode == 'J'){
                transportCostPerPerson = 2500;
                entryFeePerPerson = 2000;
                tourGuideFee = 4000;
                strcpy(destination, "Jollywood park");
                jollywoodParkTours++;
            }else if(destinationCode == 'M'){
                transportCostPerPerson = 3700;
                entryFeePerPerson = 600;
                tourGuideFee = 5200;
                strcpy(destination, "Mom's River");
                momsRiversTours++;
            }else if(destinationCode == 'A'){
                transportCostPerPerson = 3000;
                entryFeePerPerson = 4000;
                tourGuideFee = 0;
                strcpy(destination, "Adventurama");
                adveturamaTours++;
            }

            /*add booked tour to total*/
            totalTours++;

            /* calculate discounts*/
            transportCostPerPersonDiscount = transportCostPerPerson/100 * transportDiscount;
            discountedTransportCostPerPerson = transportCostPerPerson - transportCostPerPersonDiscount;
            totalDiscount = travelPartySize*transportCostPerPersonDiscount;

            /*calculate totals*/
            transportCostTotal = discountedTransportCostPerPerson * travelPartySize;
            entryFeeTotal = entryFeePerPerson * travelPartySize;
            tripTotal = transportCostTotal + entryFeeTotal + tourGuideFee;
            balanceDue = tripTotal - deposit;

            /*add travellers in this trip to total travellers*/
            travellersTotal += travelPartySize;

            /* print invoice for booking*/
            printf("_______________________________________________________________________\n\n\n\n");
            printf("_______________________________________________________________________\nINVOICE\n");
            printf("-----------------------------------------------------------------------\n");
            printf("Customer ID: %s", customerId);
            printf("\nCustomer Name: %s %s", firstName, lastName);
            printf("\nDestination: %c - %s", destinationCode, destination);
            printf("\nGuests in party: %d", travelPartySize);
            printf("\nDiscount per person: %2.f - %d%%", transportCostPerPersonDiscount, transportDiscount);
            printf("\nTotal discount: %.2f", totalDiscount);
            printf("\nTotal cost: %.2f", tripTotal);
            printf("\nFunds deposited: %.2f", deposit);
            printf("\nBalance due: %.2f", balanceDue);
            printf("\n__________________________________________________________________\n");
            printf("-------------------------------------------------------------------\n\n\n\n");

            /*allow user a chance to confirm booking*/
            if(deposit >= tripTotal){
                printf("Your booking is fully payed for and has been confirmed");
                printf("\nChange due:%.2f\n\n", deposit - tripTotal);
            }else{
                while(confirmBooking!= 'y' && confirmBooking!= 'n')
                {
                    printf("\n\nWould you like to confirm this booking by paying the balance?\n(press y for yes or n for no): ");
                    fflush(stdin);
                    scanf("%c", &confirmBooking);
                    if(confirmBooking!= 'y' && confirmBooking!= 'n'){
                        printf("\nThe value you entered is invalid.\n");
                    }
                }
                if(confirmBooking == 'y'){
                    printf("\nTo confirm booking pay the balance of: %.2f\n", balanceDue);
                    confirmedBookingsTotal++;
                }
            }
            printf("-------------------------------------------------------------------\n");
            printf("___________________________________________________________________\n\n\n\n");

        }//end tour loop

        averageTravellersPerTour = travellersTotal/totalTours;
        printf("________________________________________________________________");
        printf("\nThank you for booking tours with us.");
        printf("\nTours booked - Jollywood Park: %d", jollywoodParkTours);
        printf("\n--------------------------------------------------------------");
        printf("\nTours booked - Adventurama: %d", adveturamaTours);
        printf("\n--------------------------------------------------------------");
        printf("\nTours booked - Moms River: %d", momsRiversTours);
        printf("\n--------------------------------------------------------------");
        printf("\nTours booked - Total: %d", totalTours);
        printf("\n--------------------------------------------------------------");
        printf("\nTotal persons booked: %d", travellersTotal);
        printf("\n--------------------------------------------------------------");
        printf("\nAverage of person per tour: %d", averageTravellersPerTour);
        printf("\n--------------------------------------------------------------\n\n\n");
    }// end programme loop

    return 0;
}
