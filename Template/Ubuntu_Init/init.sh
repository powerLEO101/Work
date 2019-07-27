echo "请在root环境下运行本程序（sudo su）..."
sleep 2s
sudo apt-get install unity-tweak-tool -y
sudo apt-get install zsh git -y
git clone https://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh 
echo "export ZSH=\$HOME/.oh-my-zsh\n\
ZSH_THEME=\"robbyrussell\"\n\
plugins=(git)\n\
source \$ZSH/oh-my-zsh.sh\n\
export PATH=\$HOME/bin:/usr/local/bin:\$PATH" >> ~/.zshrc
sudo apt-get update
#-------------Install Monaco-----------------
URL="https://github.com/todylu/monaco.ttf/blob/master/monaco.ttf?raw=true"
FILENAME=${URL##*/}
FONT_DIR=/usr/share/fonts/truetype/custom/
echo $FILENAME
echo $FONT_DIR
echo "Start install"
sudo mkdir -p $FONT_DIR
echo "Downloading font"
wget -c $URL
echo "Installing font"
sudo mv $FILENAME $FONT_DIR
echo "Updating font cache"
sudo fc-cache -f -v
echo "Enjoy"
#-------------Install Monaco-----------------
