//
//  ViewController.swift
//  InterfaceBuilderBasics
//
//  Created by Pavel Prykhodko on 12.01.2020.
//  Copyright © 2020 Pavel Prykhodko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {


    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBOutlet var mainLabel: UILabel!
    
    @IBAction func changeTitla(_ sender: Any) {
        mainLabel.text = "This app rocks!"
    }
    
}

