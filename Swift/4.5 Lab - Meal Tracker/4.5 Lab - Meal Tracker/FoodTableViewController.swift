//
//  FoodTableViewController.swift
//  4.5 Lab - Meal Tracker
//
//  Created by Pavel Prykhodko on 17.05.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import UIKit

class FoodTableViewController: UITableViewController {
    
    var meals: [Meal] {
        return [
            Meal(name: "breakfast", food: [
                Food(name: "banana", description: "fruit"),
                Food(name: "oatmeal", description: "groats"),
                Food(name: "honey", description: "ingredient")
            ]),
            Meal(name: "lunch", food: [
                Food(name: "rice", description: "groats"),
                Food(name: "chicken", description: "meat"),
                Food(name: "apple", description: "fruit")
            ]),
            Meal(name: "dinner", food: [
                Food(name: "strawberry", description: "berry"),
                Food(name: "pear", description: "fruit"),
                Food(name: "tea", description: "drink")
            ])
        ]
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false
        
        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem
    }
    
    // MARK: - Table view data source
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return meals.count
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if section < meals.count {
            return meals[section].food.count
        }
        return 0
    }
    
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "foodCell", for: indexPath)
        
        let food = meals[indexPath.section].food[indexPath.row]
        
        cell.textLabel?.text = food.name
        cell.detailTextLabel?.text = food.description
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if section < meals.count {
            return meals[section].name
        }
        return nil
    }
}
