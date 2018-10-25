pipeline {
    agent any
    stages {
        stage('Shebang') {
            steps {
                sh '''#!/bin/bash
                      echo good'''
            }
        }
    }
}
