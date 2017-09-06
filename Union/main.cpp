#include <iostream>
#include <iomanip>

using namespace std;

//ENUMS MAKES CODE MORE READABLE
enum buissDays
{
    SUNDAY =0,
    MONDAY=1,
    TUESDAY=2,
    WEDNESDAY=3,
    THURSDAY =4,
    FRIDAY=5,
    SATURDAY =6

};
enum colors
{
    red,orange,yellow,green,blue,indigo,violet//,orange <-- would make it not run because its treated a s literal

};
enum liquidStates
{
    freezing,boilling

};
string convertToString(enum buissDays);

int main()
{
    try
    {
    buissDays bizDay = WEDNESDAY;
    cout<<bizDay<<endl;

    const int ASIZE =7;
    double dailySales[ASIZE];
    double totalSales = 0.0;

    for(bizDay = MONDAY; bizDay <= FRIDAY;bizDay = (buissDays)(bizDay+1))// Casting it as busisness day because you can ++
    {
        cout<<"Enter sales amount for every day of the working week :: "<<convertToString(bizDay)<<endl;
        cin>> dailySales[bizDay];

        totalSales+= dailySales[bizDay];
    }
    cout<<"The sales of all the days was:: "<<fixed<<setprecision(2)<<endl;


    double drinkTemp;
    cout<<"Enter what the temperature of your drink"<<endl;
    cin>>drinkTemp;

    if(drinkTemp <= freezing || drinkTemp >= boilling)
    {
        cout<<"You can't drink that"<<endl;
    }
    else
    {
        cout<<"You can drink"<<endl;
    }


    }
    catch(exception e)
    {
        cout<<"Error as occurred"<<endl;
        return -1;
    }

    return 0;
}

string convertToString(buissDays workday)
{
    /* TAKES ALONG TIME
    swtich(workday)
    {

        case MONDAY
            return "Monday";
        case TUESDAY:
            return" TUESDAY";
        case WEDNESDAY:
            return"Wednesday";
        case THURSDAY:
            return"Thursday";
        case FRIDAY:
            return"Friday";
        case SATURDAY:
            return"Saturday";
        case SUNDAY:
            return"Sunday";
        default:
            return"Not a valid day";
    }
    */
    string days[7] = {"SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};// ONLY 2 LINES
    return days[(int)(workday)];

}
