// SPDX-License-Identifier: GPL-3.0 
pragma solidity ^0.8.0; 
/// @title A contract to demonstrate the working of the interface
/// @author Jitendra Kumar
/// @notice For now, this contract just shows how an interface is implemented in a smart contract

import "/Exp 7/Interfaces_1.sol";

contract MyContract is InterfaceExample{

	// Private variables
	uint private num1;
	uint private num2;

	// Function definitions of functions
	// declared inside an interface
	function getStr() public view virtual override returns(string memory){
		return "GeeksForGeeks";
	}
	
	// Function to set the values
	// of the private variables
	function setValue(
	uint _num1, uint _num2) public virtual override{			 
		num1 = _num1;
		num2 = _num2;
	}
	
	// Function to add 2 numbers
	function add(
	) public view virtual override returns(uint){
		return num1 + num2;
	}
}

contract call{
	
	//Creating an object
	InterfaceExample obj;

	constructor(){
		obj = new MyContract();
	}
	
	// Function to print string
	// value and the sum value
	function getValue(
	) public returns(string memory,uint){
		obj.setValue(10, 16);
		return (obj.getStr(),obj.add());
	}
}
