pipeline {
  agent any
  stages {
    stage('Clone repository') {
      steps{
        checkouts([$class: 'GitSCM',
                   branches: [[name: '*/main']],
                   userRemoteConfigs: [[url: 'https://github.com/ShreyaGunnan/PES1UG21CS573_Jenkins.git']]])
      }
    }
    stage('Build'){
      steps{
        build 'PES1UG21CS573-1'
        sh 'g++ main.cpp -o output'
      }
    }
    stage('Test'){
      steps{
        sh './output'
      }
    }
    stage('Deploy'){
      steps{
        echo 'deploy'
      }
    }
  }
  post{
    failure{
      error 'Pipeline Failed'
    }
  }
}
