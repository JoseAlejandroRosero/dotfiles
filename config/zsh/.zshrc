
[ -f "$XDG_CONFIG_HOME/zsh/alias" ] && source "$XDG_CONFIG_HOME/zsh/alias"

autoload -U compinit && compinit
# The following lines were added by compinstall

zstyle ':completion:*' completer _complete _ignored
zstyle ':completion:*' completions 1
zstyle ':completion:*' expand prefix suffix
zstyle ':completion:*' format 'Completing %d'
zstyle ':completion:*' group-name ''
zstyle ':completion:*' ignore-parents pwd .. directory
zstyle ':completion:*' list-prompt %SAt %p: Hit TAB for more, or the character to insert%s
zstyle ':completion:*' list-suffixes true
zstyle ':completion:*' matcher-list '' 'm:{[:lower:][:upper:]}={[:upper:][:lower:]}' 'm:{[:lower:][:upper:]}={[:upper:][:lower:]} r:|[._-]=** r:|=**' 'l:|=* r:|=*'
zstyle ':completion:*' menu select=3
zstyle ':completion:*' original true
zstyle ':completion:*' select-prompt %SScrolling active: current selection at %p%s
zstyle :compinstall filename '/home/newyorleck/.zshrc'

autoload -Uz compinit
compinit
# End of lines added by compinstall
# Lines configured by zsh-newuser-install
HISTFILE=$XDG_CACHE_HOME/zsh/zsh_history
HISTSIZE=1000000
SAVEHIST=1000000
setopt autocd extendedglob notify append_history inc_append_history share_history
bindkey -v
# End of lines configured by zsh-newuser-install

unsetopt prompt_sp

source <(fzf --zsh)

bindkey "^J" history-search-forward
bindkey "^K" history-search-backward
bindkey "^R" fzf-history-widget

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source $HOME/.local/src/awww/completions/_awww

NEWLINE=$'\n'
PROMPT="${NEWLINE}%K{#2E3440}%F{#E5E9F0}$(date +%_I:%M%P) %K{#3b4252}%F{#ECEFF4} %n %K{#4c566a} %~ %f%k ❯ "
echo -e "${NEWLINE}\x1b[38;5;137m\x1b[48;5;0m it's$(print -P '%D{%_I:%M%P}\n') \x1b[38;5;180m\x1b[48;5;0m $(uptime -p | cut -c 4-) \x1b[38;5;223m\x1b[48;5;0m $(uname -r) \033[0m"

#sneakers
#fastfetch
unimatrix -f -b -s 96 -w
