pipeline {
  agent any
  stages {
    stage('Clone repository') {
      steps {
        script {
          checkout([$class: 'GitSCM',
                   branches: [[name: '*/main']],
                   userRemoteConfigs: [[url: 'https://github.com/ShreyaGunnan/PES1UG21CS573_Jenkins.git']]])
        }
      }
    }
    stage('Build') {
      steps {
        script {
          sh 'g++ main.cpp -o output'
        }
      }
    }
    stage('Test') {
      steps {
        script {
          sh './output'
        }
      }
    }
    stage('Deploy') {
      steps {
        echo 'deploy'
      }
    }
  }
  post {
    failure {
      error 'Pipeline Failed'
    }
  }
}
