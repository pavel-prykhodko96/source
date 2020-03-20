//
//  ViewController.swift
//  Light
//
//  Created by Pavel Prykhodko on 12.01.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    var lightOn = true
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        updateUI()
    }

    @IBAction func buttonPressed(_ sender: Any) {
        lightOn.toggle()//if == true change to false and vice versa
        updateUI()
    }
    
    func updateUI() {
        view.backgroundColor = lightOn ? .white : .black
    }
}

