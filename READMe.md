Estate is defined by:
   Adress of the estate;
   Owner;
   Price;
   Land area;
To implement functionality that displays information about a property in the console. Each property can be one of the following types:
   Flat - contains information on the number of rooms and floors.
   House - contains information on the number of rooms, floors and yard   area.
   Plot (of land) - contains information about available communications (list of elements of enumerable type of communications ( water, electricity, close proximity to roads, sewage) and land.
In order for a property to exist it must be registered.
Define a class that maintains a list of registered real estates RealEstates, storing a container of class objects Estate, in which objects of the property type will be stored.
We can both register and remove a property from the list of registered properties. In order to find a certain property we have to use brokers. Each has a list of registered properties, but uses different evaluation of property on demand. All brokers raise property prices to include their fees.
Each broker is defined by:
   Name
   Percentage
   Type
We differeniate three types of brokers:
   HelpfulBroker / ThoughtfulBroker - has a lis of VIP ads, which are previewed before the rest of the ads and imporves the chances of a property to be presented.
   DishonestBroker  - Has a list of VIP ads, but presents them with improves price and land at random.
   SimpleBroker - Does not behave any differently than a regular search engine.
To implement functionality that allows adding and removing property to the list of VIP properties in the brokers of the first two types.
In order to inspect properties, we will have to choose a broker to service us. Okay, so how do we search?
Once we have chosen a broker, we can submit our criteria (the setting of a criteria, can be done through a menu or other suitable and selected by you ways) for search and he will provide us with a list of suggestions.
To do this, the program must support the following functionalities:
   Search by different requirements of the client 
   - type of property, price from set interval,land size,populated place
   -List of all properties of a given type, sorted by price in descending order. 
Demonstrate the operation of the RealEstates class by defining an object from this class and list of brokers and provide an opportunity for different reports that demonstrate search methods.







