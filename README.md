<pre>
The <strong> Estate </strong> class contains the following fields
    ● <strong> TypeOfEstate </strong>;
    ● <strong> Address </strong>;
    ● <strong> Owner </strong>;
    ● <strong> Price </strong>;
    ● <strong> space </strong>;
We need to implement functionality that displays information about a property in the console.
Each property can be one of the following types:
● <strong> Flat </strong> - Contains information about the number of rooms and floor.
● <strong> House </Strong> - contains information about the number of rooms, number of floors, yard area.
● <strong> Plot </strong> - contains information about available communications (list of items of enumerable Communication type (water, electricity, telephone, roadside, sewer) and area.
In order for a property to exist, it must be registered. Define a class that maintains a list of registered real estate <strong> RealEstates </strong>, storing a container of directories to objects of class <strong> Estate </strong>, in which objects of the property type will be stored.
We can both register and remove a property from the list of registered properties.
In order to be able to find a certain property we have to use brokers.
Each has a list of registered properties, but uses a different property valuation when searching. All brokers raise property prices to include their fees.
Each broker is defined by:
● <strong> Name </strong>
● <strong> Percentage </strong>
● <strong> TypeOfBroker </strong>
We distinguish three types of brokers:
        ○ <strong> HelpfulBroker / ThoughfulBroker </strong> - has a list of VIP ads that are displayed before the other ads and improves the chance of a property being presented.
        ○ <strong> DishonestBroker </strong> - has a list of VIP ads, but presents them with improved price and area at random.
        ○ <strong> SimpleBroker </strong> - Doesn't behave any differently than a regular search engine.
To implement functionality that allows adding and removing a property to the list of VIP properties in the brokers of the first two types.
In order to inspect properties, we will have to choose a broker to serve us.
Okay, so how do we search?
Once we have chosen a broker, we can submit our criteria (setting criteria can be done through a menu or in another appropriate and chosen by you) search and he will present us with a list of proposals.
To this end, the program must support the following functionalities:
● Search by different requirements of the client - type of property, price from a given interval, area, available communications, given location.
● List of all properties of a given type, sorted by price in descending order.
Demonstrate the performance of the <strong> RealEstates </strong> class by defining an object in that class and a list of brokers, and provide an opportunity for various references that demonstrate search methods.
</pre>
