//
//  EmployeeTypeTableViewController.swift
//  EmployeeRoster
//
//  Created by Pavel Prykhodko on 20.06.2020.
//

import UIKit

protocol EmployeeTypeDelegate: AnyObject {
    func didSelect(employeeType: EmployeeType)
}

class EmployeeTypeTableViewController: UITableViewController {
    weak var delegate: EmployeeTypeDelegate?
    
    var employeeType: EmployeeType?
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem
    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return EmployeeType.all.count
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "EmployeeTypeCell", for: indexPath)
        let type = EmployeeType.all[indexPath.row]
        cell.textLabel?.text = type.description()

        if employeeType == type {
            cell.accessoryType = .checkmark
        } else {
            cell.accessoryType = .none
        }
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        employeeType = EmployeeType.all[indexPath.row]
        delegate?.didSelect(employeeType: employeeType!)
        tableView.reloadData()
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
