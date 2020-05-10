//
//  AthleteFormViewController.swift
//  FavoriteAthlete
//
//  Created by Pavel Prykhodko on 10.05.2020.
//

import UIKit

class AthleteFormViewController: UIViewController {
    @IBOutlet var nameTextField: UITextField!
    @IBOutlet var ageTextField: UITextField!
    @IBOutlet var leagueTextField: UITextField!
    @IBOutlet var teamTextField: UITextField!
    
    @IBAction func saveButtonPressed(_ sender: Any) {
        guard let name = nameTextField.text,
            let age = ageTextField.text,
            let league = leagueTextField.text,
            let team = teamTextField.text else {return}
        
        athlete = Athlete(name: name, age: age, league: league, team: team)
        performSegue(withIdentifier: "fromFormToTable", sender: self)
    }
    
    var athlete: Athlete?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        updateView()
    }
    
    func updateView() {
        if let athlete = athlete {
            nameTextField.text = athlete.name
            ageTextField.text = athlete.age
            leagueTextField.text = athlete.age
            teamTextField.text = athlete.team
        }
    }
}
