Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty"

  config.vm.provision "shell", privileged: true, run: "once", inline: <<-SHELL
    sudo apt-get -y --force-yes install build-essential git wget curl
    sudo apt-get -y --force-yes install build-essential
    sudo apt-get -y --force-yes install git-all
    sudo apt-get -y --force-yes install g++ -std=gnu++11
    sudo apt-get clean all

    alias g++="g++ -std=c++0x"

  SHELL
end
