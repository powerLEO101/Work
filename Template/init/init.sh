sudo apt-get install unity-tweak-tool 
sudo add-apt-repository ppa:noobslab/themes
sudo add-apt-repository ppa:numix/ppa
sudo apt-get update
sudo apt-get install flatabulous-theme
sudo apt-get install numix-gtk-theme numix-icon-theme-circle
sudo apt-get install zsh git
git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh 
chsh -s /bin/zsh  
echo "export ZSH=\$HOME/.oh-my-zsh\n\
ZSH_THEME=\"robbyrussell\"\n\
plugins=(git)\n\
source \$ZSH/oh-my-zsh.sh\n\
export PATH=\$HOME/bin:/usr/local/bin:\$PATH" >> ~/.zshrc
chsh -s /bin/zsh  
ssh-keygen -t rsa -C "3256870400@qq.com"
sudo add-apt-repository ppa:a-v-shkop/chromium
sudo apt-get update
sudo apt-get install chromium-browser