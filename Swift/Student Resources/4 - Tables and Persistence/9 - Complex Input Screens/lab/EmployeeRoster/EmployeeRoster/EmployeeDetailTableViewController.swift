
import UIKit

class EmployeeDetailTableViewController: UITableViewController, UITextFieldDelegate, EmployeeTypeDelegate {
    
    struct PropertyKeys {
        static let unwindToListIndentifier = "UnwindToListSegue"
    }
    let dateCellIndexPath = IndexPath(row: 1, section: 0)
    let datePickerCellIndexPath  = IndexPath(row: 2, section: 0)
    
    var isEditingBirthday = false {
        didSet {
            tableView.reloadData()
        }
    }
    var employee: Employee?
    var employeeType: EmployeeType?
    
    @IBOutlet var nameTextField: UITextField!
    @IBOutlet var dobLabel: UILabel!
    @IBOutlet var dobDatePicker: UIDatePicker!
    @IBOutlet var employeeTypeLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        updateView()
    }
    
    // MARK: - Data Source
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if indexPath == dateCellIndexPath {
            isEditingBirthday.toggle()
            if isEditingBirthday {
                let dateFormatter = DateFormatter()
                dateFormatter.dateStyle = .medium
                dobLabel.textColor = .black
                dobLabel.text = dateFormatter.string(from: dobDatePicker.date)
            }
        }
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        if indexPath == datePickerCellIndexPath { // Date picker index
            if isEditingBirthday {
                return 216
            } else {
                return 0
            }
        } else {
            return UITableView.automaticDimension
        }
    }
    
    func updateView() {
        if let employee = employee {
            navigationItem.title = employee.name
            nameTextField.text = employee.name
            let dateFormatter = DateFormatter()
            dateFormatter.dateStyle = .medium
            dobLabel.text = dateFormatter.string(from: employee.dateOfBirth)
            dobLabel.textColor = .black
            employeeTypeLabel.text = employee.employeeType.description()
            employeeTypeLabel.textColor = .black
        } else {
            navigationItem.title = "New Employee"
        }
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        return false
    }
    
    func didSelect(employeeType: EmployeeType) {
        self.employeeType = employeeType
        employeeTypeLabel.textColor = .black
        employeeTypeLabel.text = employeeType.description()
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "SelectEmployeeTypeSegue" {
            let employeeTypeTableViewController = segue.destination as? EmployeeTypeTableViewController
            employeeTypeTableViewController?.delegate = self
            employeeTypeTableViewController?.employeeType = employeeType
        }
    }
    
    // MARK: - Actions
    @IBAction func saveButtonTapped(_ sender: Any) {
        if let name = nameTextField.text,
            let employeeType = self.employeeType {
            employee = Employee(name: name, dateOfBirth: dobDatePicker.date, employeeType: employeeType)
            performSegue(withIdentifier: PropertyKeys.unwindToListIndentifier, sender: self)
        }
    }
    
    @IBAction func cancelButtonTapped(_ sender: Any) {
        employee = nil
        performSegue(withIdentifier: PropertyKeys.unwindToListIndentifier, sender: self)
    }
    
    @IBAction func datePickerValueChanged(_ sender: UIDatePicker) {
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = .medium
        dobLabel.textColor = .black
        dobLabel.text = dateFormatter.string(from: dobDatePicker.date)
    }
}
