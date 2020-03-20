//
//  ViewController.swift
//  lesson_1_8_IBBasics
//
//  Created by Pavel Prykhodko on 28.12.2019.
//  Copyright © 2019 Pavel Prykhodko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var myButton: UIButton!
    
    @IBAction func buttonPressed(_ sender: Any) {
        print ("The button was pressed")
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        myButton.setTitleColor(.red, for: .normal)
        // Do any additional setup after loading the view.
    }


}

