<?php
class Flight {

    public $airline;
    public $flightNumber;
    public $destination;

  
    public function setFlight($airline, $flightNumber, $destination) {
        $this->airline = $airline;
        $this->flightNumber = $flightNumber;
        $this->destination = $destination;
    }

    public function getFlight() {
        return "Airline: " . $this->airline . ", Flight Number: " . $this->flightNumber . ", Destination: " . $this->destination;
    }
}


$flight1 = new Flight();


$flight1->setFlight("Nepal Airlines", "RA123", "Kathmandu");


echo $flight1->getFlight();
?>