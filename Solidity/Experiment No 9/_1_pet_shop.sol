pragma solidity ^0.8.0;

contract PetShop {
    address public owner;
    uint256 public petCount = 0;

    struct Pet {
        uint256 id;
        string name;
        uint256 price;
        address owner;
        bool sold;
    }

    mapping(uint256 => Pet) public pets;

    event PetCreated(
        uint256 id,
        string name,
        uint256 price,
        address owner,
        bool sold
    );
    event PetPurchased(
        uint256 id,
        string name,
        uint256 price,
        address owner,
        bool sold
    );

    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can call this function");
        _;
    }

    constructor() {
        owner = msg.sender;
    }

    function createPet(string memory _name, uint256 _price) public onlyOwner {
        require(bytes(_name).length > 0, "Pet name cannot be empty");
        require(_price > 0, "Pet price must be greater than zero");
        petCount++;
        pets[petCount] = Pet(petCount, _name, _price, msg.sender, false);
        emit PetCreated(petCount, _name, _price, msg.sender, false);
    }

    function purchasePet(uint256 _id) public payable {
        Pet memory _pet = pets[_id];
        require(_pet.id > 0 && _pet.id <= petCount, "Invalid pet ID");
        require(!_pet.sold, "Pet already sold");
        require(msg.value >= _pet.price, "Insufficient funds");

        _pet.owner = msg.sender;
        _pet.sold = true;
        pets[_id] = _pet;

        payable(owner).transfer(msg.value);
        emit PetPurchased(
            _pet.id,
            _pet.name,
            _pet.price,
            _pet.owner,
            _pet.sold
        );
    }
}
