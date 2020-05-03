//
//  ViewController.swift
//  Login
//
//  Created by Pavel Prykhodko on 26.04.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }
    
    @IBOutlet var userNameText: UITextField!
    @IBOutlet var forgotUserNameButton: UIButton!
    @IBOutlet var forgotPasswordButton: UIButton!
    
    @IBAction func forgotUserName(_ sender: UIButton) {
        performSegue(withIdentifier: "forgottenUserNameOrPassword", sender: forgotUserNameButton)
    }
    @IBAction func forgotPassword(_ sender: UIButton) {
        performSegue(withIdentifier: "forgottenUserNameOrPassword", sender: forgotPasswordButton)
    }
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        guard let sender = sender as? UIButton else {return}
        
        if sender == forgotUserNameButton {
            segue.destination.navigationItem.title = "Forgot Username"
        } else if sender == forgotPasswordButton {
            segue.destination.navigationItem.title = "Forgot Password"
        } else {
            segue.destination.navigationItem.title = userNameText.text
        }
    }
}

