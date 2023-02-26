<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <board-game-store>
            <xsl:for-each select="board-game-store/game">
                <game>
                    <xsl:call-template name="game-title"/>
                    <game-rating>
                        <xsl:call-template name="game-rating"/>
                    </game-rating>
                    <game-skill>
                        <xsl:call-template name="game-skill"/>
                    </game-skill>
                </game>
            </xsl:for-each>
        </board-game-store>
    </xsl:template>

    <xsl:template name="game-title">
        <code>
            <xsl:value-of select="id"/>
        </code>
        <title>
            <xsl:value-of select="title"/>
        </title>
    </xsl:template>

    <xsl:template name="game-rating">
        <xsl:value-of select="rating"/>
    </xsl:template>

    <xsl:template name="game-skill">
        <xsl:value-of select="skill"/>
    </xsl:template>

</xsl:stylesheet>
